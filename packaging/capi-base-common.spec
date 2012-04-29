Name:       capi-base-common
Summary:    Common header files of Tizen Native API
Version: 0.1.0
Release:    7
Group:      TO_BE/FILLED_IN
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
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
cmake . -DCMAKE_INSTALL_PREFIX=/usr


make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install



%files

%files devel
/usr/include/*.h
/usr/lib/pkgconfig/capi-base-common.pc


