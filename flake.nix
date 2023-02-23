{
  description = "A flake for my QMK environment.";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";

      pkgs = import nixpkgs {
        inherit system;
      };
    in {
      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs; [
          nil
          qmk
          qmk-udev-rules
          gnumake
        ];
        shellHook = ''
          export QMK_HOME="$(pwd)/qmk_firmware"
          alias qmk="qmk --config-file $(qmk)/qmk.ini"
        '';
      };

  };
}
