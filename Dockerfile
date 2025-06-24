FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    gettext \
    git \
    build-essential \
    autoconf \
    libtool \
    libxml2-dev \
    pkg-config \
    libssl-dev \
    libpq-dev \
    wget \
    curl \
    sudo \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /opt

# Install legacy Bison 1.28
RUN apt-get -y remove bison && \
    wget https://ftp.gnu.org/gnu/bison/bison-1.28.tar.gz && \
    tar -xvf bison-1.28.tar.gz && \
    cd bison-1.28 && \
    ./configure --prefix=/usr/local/bison && \
    make && make install && \
    ln -sf /usr/local/bison/bin/bison /usr/bin/bison && \
    ln -sf /usr/local/bison/bin/yacc /usr/bin/yacc && \
    rm -rf bison-1.28 bison-1.28.tar.gz

# Clone source
RUN git clone https://github.com/RemotiQ/smsgateway.git /opt/smsgateway

# Build gateway core
WORKDIR /opt/smsgateway
RUN ./bootstrap.sh && \
    CFLAGS="-fcommon" ./configure \
        --with-pgsql \
        --disable-wap \
        --enable-debug \
        --enable-assertions \
        --with-defaults=speed \
        --disable-localtime \
        --enable-start-stop-daemon && \
    touch .depend && chmod 0755 gw-config && \
    mkdir -p /usr/local/kannel && \
    make bindir=/usr/local/kannel install

# Setup logs
RUN mkdir -p /etc/kannel /var/log/kannel && \
    mkdir -p /var/log/kannel/gateway /var/log/kannel/smsbox /var/log/kannel/wapbox \
             /var/log/kannel/smsc /var/log/kannel/sqlbox /var/log/kannel/smppbox && \
    chmod -R 755 /var/log/kannel

# Copy configuration (override externally if needed)
COPY conf/kannel.conf /etc/kannel/kannel.conf
COPY conf/kannel.default /etc/default/kannel
COPY conf/kannel.init /etc/init.d/kannel

RUN chmod +x /etc/init.d/kannel && \
    update-rc.d kannel defaults

# Startup script
#COPY start-kannel.sh /usr/local/bin/start-kannel.sh
#RUN chmod +x /usr/local/bin/start-kannel.sh

EXPOSE 13000 13013 13014

#ENTRYPOINT ["/usr/local/bin/start-kannel.sh"]
