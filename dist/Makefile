VERSION=0.1.0

rpm-prep:
	mkdir -p ${HOME}/rpmbuild/SOURCES/
	tar --transform="s/\./gru-${VERSION}/" -cf ${HOME}/rpmbuild/SOURCES/gru-${VERSION}.tar.gz --exclude=./build --exclude=.git --exclude=*.bz ./ --gzip

rpm: rpm-prep
	rpmbuild -ba dist/fc-rpm.spec
