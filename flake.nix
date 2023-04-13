{
  description = "PlatformIO STM32 devShell";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/21.11";
    nixpkgs-unstable.url =
      "nixpkgs/nixpkgs-unstable"; # for packages on the edge

    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, nixpkgs-unstable, utils, ... }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
        pkgs' = import nixpkgs-unstable { inherit system; };
      in {
        devShells.default = pkgs.mkShell {
          name = "stm32-on-nix-project"; # rename me
          buildInputs = with pkgs; [
            # bear
            ccls
            # cmake
            # gcc-arm-embedded
            just
            openocd
            pkgs'.platformio # 21.11 version is too old
            stlink
          ];
          shellHook = ''
            # update based on your environment and board
            pio project init --ide emacs --board nucleo_f103rb
          '';
        };
      });
}
