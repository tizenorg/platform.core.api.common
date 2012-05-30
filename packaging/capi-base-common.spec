Name:       capi-base-common
Summary:    Common header files of Tizen Native API
Version: 0.1.0
Release:    7
Group:      TO_BE/FILLED_IN
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
Source1001: packaging/capi-base-common.manifest 
BuildRequires:  cmake

%description
Common header files of Tizen Native API

  
%package devel  
Summary:  Common header files of Tizen Native API (Development)  
Group:    TO_BE/FILLED_IN  
Requires: %{name} = %{version}-%{release}  
  
%description devel
Common header files of Tizen Native API

%prep
%setup -q


%build
cp %{SOURCE1001} .
cmake . -DCMAKE_INSTALL_PREFIX=/usr


make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install



%files
%manifest capi-base-common.manifest

%files devel
%manifest capi-base-common.manifest
/usr/include/*.h
/usr/lib/pkgconfig/capi-base-common.pc


