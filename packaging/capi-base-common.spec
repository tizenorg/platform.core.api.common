Name:       capi-base-common
Summary:    Common header files of Tizen Native API
Version:    0.2.0
Release:    1
Group:      System/Libraries
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
Source1001: capi-base-common.manifest

BuildRequires:    cmake
Requires(post):   /sbin/ldconfig  
Requires(postun): /sbin/ldconfig

%description
This is Common header files of Tizen Native API
  
%package devel  
License:  Apache-2.0
Summary:  Common header files of Tizen Native API (Development)
Group:    System/Libraries
Requires: %{name} = %{version}-%{release}  
  
%description devel
This is Common header files of Tizen Native API

%prep
%setup -q
cp %{SOURCE1001} .

%build
MAJORVER=`echo %{version} | awk 'BEGIN {FS="."}{print $1}'`
%cmake . -DFULLVER=%{version} -DMAJORVER=${MAJORVER}

%__make %{?_smp_mflags}

%install
%make_install
mkdir -p %{buildroot}%{_datadir}/license
cp LICENSE %{buildroot}%{_datadir}/license/%{name}

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%manifest %{name}.manifest
%{_libdir}/libcapi-base-common.so*
%{_datadir}/license/%{name}

%files devel
%manifest %{name}.manifest
%{_includedir}/*.h
%{_libdir}/pkgconfig/capi-base-common.pc
%{_datadir}/license/%{name}

