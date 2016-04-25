Name:       capi-base-common
Summary:    Common header files of Tizen Native API
Version:    0.4.3
Release:    1
Group:      Base
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz

BuildRequires:    cmake
Requires(post):   /sbin/ldconfig  
Requires(postun): /sbin/ldconfig

%description
Common header files of Tizen Native API
  
%package devel  
License:  Apache-2.0
Summary:  Common header files of Tizen Native API (Development)
Group:    Base
Requires: %{name} = %{version}-%{release}  
  
%description devel
Common header files of Tizen Native API

%prep
%setup -q

%build

MAJORVER=`echo %{version} | awk 'BEGIN {FS="."}{print $1}'`

cmake . -DCMAKE_INSTALL_PREFIX=%{_prefix} -DLIB_INSTALL_DIR:PATH=%{_libdir} -DINCLUDE_INSTALL_DIR:PATH=%{_includedir} \
-DFULLVER=%{version} -DMAJORVER=${MAJORVER}

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}

%make_install
mkdir -p %{buildroot}/usr/share/license
cp LICENSE %{buildroot}/usr/share/license/%{name}

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%manifest %{name}.manifest
/usr/share/license/%{name}
%{_libdir}/libcapi-base-common.so*

%files devel
%manifest %{name}.manifest
%{_includedir}/*.h
%{_libdir}/pkgconfig/capi-base-common.pc
