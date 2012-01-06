Name:       capi-base-common
Summary:    TO BE FILLED IN
Version:    0.1.0
Release:    1
Group:      TO_BE/FILLED_IN
License:    TO BE FILLED IN
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  cmake

%description




%prep
%setup -q


%build
cmake . -DCMAKE_INSTALL_PREFIX=/usr


make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install



%files
/usr/include/*.h
/usr/lib/pkgconfig/capi-base-common.pc


