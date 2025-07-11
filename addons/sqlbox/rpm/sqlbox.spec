%define version cvs
%define release pgsql_%(echo svn-r | cut -d- -f2)

Summary: DB-Based Kannel Box for message queueing.
Name: sqlbox
Version: %{version}
Release: %{release}
License: Kannel
Group: System Environment/Daemons
URL: http://www.kannel.org/~aguerrieri/
Source0: sqlbox-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root
BuildRequires: bison, byacc, flex
BuildRequires: kannel-devel, openssl-devel, zlib-devel
BuildRequires: postgresql-devel >= 7.2

%description
Sqlbox is a special Kannel box that sits between bearerbox and smsbox and uses
a database queue to store and forward messages.

Messages are queued on a configurable table (defaults to send_sms) and moved to
another table (defaults to sent_sms) afterwards.

You can also manually insert messages into the send_sms table and they will be sent
and moved to the sent_sms table as well. This allows for fast and easy injection
of large amounts of messages into Kannel.

%prep
rm -rf %{buildroot}
%setup -q

%build
%configure
%{__make}

%install
%{__rm} -rf %{buildroot}
%makeinstall
%{__mkdir_p} %{buildroot}%{_sbindir}
%{__mkdir_p} %{buildroot}%{_var}/log/kannel/
%{__mkdir_p} %{buildroot}%{_var}/spool/kannel/

%{__install} -D -m 0640 example/sqlbox.conf.example %{buildroot}%{_sysconfdir}/kannel/sqlbox.conf

strip %{buildroot}%{_sbindir}/sqlbox

%clean
%{__rm} -rf %{buildroot}

#%pre

#%post

#%preun

#%postun


%files
%defattr(-, root, root, 0755)
%doc AUTHORS COPYING ChangeLog NEWS README UPGRADE
%attr(0640, kannel, kannel) %config(noreplace) %{_sysconfdir}/kannel/sqlbox.conf
%{_sbindir}/*
%attr(0750, kannel, kannel) %dir %{_var}/log/kannel/
%attr(0750, kannel, kannel) %dir %{_sysconfdir}/kannel/


%changelog
* Wed Nov 19 2008 Alejandro Guerrieri <aguerrieri at kannel dot org>
- First RPM version for Sqlbox
