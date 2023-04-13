{
  description = "PlatformIO STM32 devShell";

  inputs = {
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils, ... }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in {
        devShells.system = pkgs.mkShell {
          name = "stm32-on-nix-project"; # rename me
          buildInputs = with pkgs; [
            # bear
            ccls
            # cmake
            gcc-arm-embedded
            just
            openocd
            platformio
            stlink
          ];
          shellHook = ''
            # update based on your environment and board
            pio project init --ide emacs --board nucleo_f103rb
          '';
        };
      });
}
