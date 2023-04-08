{
  description = "PlatformIO STM32 devShell";

  inputs = {
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils, ... }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShell = pkgs.mkShell {
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
        };
      });
}
