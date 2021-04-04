pkgname=pacstaller
pkgver=r3.664e925
pkgrel=1
pkgdesc="Interface for pacman in C++"
arch=('x86_64')
url="https://github.com/legendary-cookie/libpaclib"
license=('GPL3')
depends=('libpaclib-git')
makedepends=('cmake>=3' 'git' 'libpaclib-git')
provides=("${pkgname}")
conflicts=("${pkgname}")
md5sums=('SKIP')
source=("pacstaller::git+https://github.com/legendary-cookie/$pkgname-cli")

validpkgkeys=("7295 48F7 4489 D805 50FA  2867 D84F 69EF 7345 8323")

pkgver() {
	cd "$srcdir/${pkgname}"
	printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

prepare() {
	cd "$srcdir/${pkgname}"
	mkdir build
}

build() {
	cd "$srcdir/${pkgname}"
	cd build
	cmake -DCMAKE_INSTALL_PREFIX=/usr/ ..
	make
}


package() {
	cd "$srcdir/${pkgname}"
	cd build
	make DESTDIR="$pkgdir/" install
}
