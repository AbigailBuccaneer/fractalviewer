with import <nixpkgs> {};
stdenv.mkDerivation rec {
  name = "fractalviewer-${version}";
  version = "0.0.1";

  src = ./.;
  buildInputs = [ stdenv cmake glfw3 ];

  installPhase = ''
    mkdir -p $out/bin
    cp mandelbrot $out/bin
  '';
}
