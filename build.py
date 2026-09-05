import argparse
import os
import shutil
import subprocess
from dataclasses import dataclass
from typing import Literal

parser = argparse.ArgumentParser(
    description="Compilalor de proyectos de la universidad"
)

parser.add_argument(
    "--folder",
    type=str,
    required=True,
    help="Ruta de la carpeta del proyecto",
)

parser.add_argument(
    "--run",
    type=bool,
    default=False,
    required=False,
    help="Indica si se debe ejecutar el proyecto después de compilarlo",
)

parser.add_argument(
    "--lenguage",
    type=str,
    default="c",
    required=False,
    help="Indica si se debe ejecutar el proyecto después de compilarlo",
)


@dataclass
class Args:
    folder: str
    run: bool = False
    lenguage: Literal["c", "c++", "cpp"] = "c"


args = Args(**(parser.parse_args().__dict__))

if not os.path.exists(args.folder):
    raise FileNotFoundError(f"La carpeta {args.folder} no existe")

path_build = os.path.join(args.folder, "build")

if os.path.exists(path_build):
    shutil.rmtree(path_build)

print(f"🛠️ Compilando proyecto en {args.folder}...\n")

files_routes: list[str] = []

for root, dirs, files in os.walk(args.folder):
    for file in files:
        extension: str = ".cpp" if args.lenguage == "c++" else ".c"
        if file.endswith(extension):
            files_routes.append(os.path.join(root, file))

if not files_routes:
    raise FileNotFoundError(
        f"No se encontraron archivos {args.lenguage} en {args.folder}"
    )

program = os.path.join(path_build, "program")

os.mkdir(path_build)

builder = "gcc" if args.lenguage == "c" else "g++"

print(f"🛠️ Compilando con {builder}...\n")

command = f"{builder} {' '.join(files_routes)} -o {program}"

print(f"🛠️ Ejecutando comando: {command}\n")

subprocess.run(command, shell=True, check=True)

print(f"✅ El proyecto se ha compilado correctamente en {program}\n")

if args.run:
    input("🚩 Presiona enter para continuar...")
    subprocess.run("clear", shell=True, check=True)
    subprocess.run(program, shell=True, check=True)
