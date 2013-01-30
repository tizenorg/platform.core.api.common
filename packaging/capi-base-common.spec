Name:           capi-base-common
Version:        0.1.0
Release:        8
License:        Apache-2.0
Summary:        Common header files of Tizen Native API
Group:          API/C API
Source0:        %{name}-%{version}.tar.gz
BuildRequires:  cmake

%description
Common header files of Tizen Native API


%package devel
Summary:        Common header files of Tizen Native API (Development)
Group:          API/C API
Requires:       %{name} = %{version}

%description devel
Common header files of Tizen Native API

%prep
%setup -q

%build
%cmake .
make %{?_smp_mflags}

%install
%make_install

%files

%files devel
%{_includedir}/*.h
%{_libdir}/pkgconfig/capi-base-common.pc


