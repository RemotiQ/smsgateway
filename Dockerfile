FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# Install required packages
RUN apt-get update && apt-get install -y \
    git \
    build-essential \
    autoconf \
    libtool \
    pkg-config \
    libssl-dev \
    libpq-dev \
    wget \
    curl \
    sudo \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /opt

# Clone the smsgateway repo
RUN git clone https://github.com/RemotiQ/smsgateway.git

# Build and install the main project
WORKDIR /opt/smsgateway
RUN ./bootstrap.sh && \
    CFLAGS="-fcommon" ./configure --with-pgsql --enable-start-stop-daemon && \
    make && \
    make install

# Build and install the sqlbox addon
WORKDIR /opt/smsgateway/addons/sqlbox
RUN ./bootstrap.sh && \
    ./bootstrap && \
    CFLAGS="-fcommon" ./configure && \
    make && \
    make install

# Default command (can be customized)
CMD ["bash"]
