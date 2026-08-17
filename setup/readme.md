# AI GENERATED README 🤖

# Environment Setup

This folder contains the templates and setup instructions for my competitive programming environment.

## 1. Operating System (Windows + WSL)

To ensure compilation flags (like ASAN) work correctly and the environment perfectly matches official competitions, always use a Linux environment. 

If you are on Windows, use **WSL (Windows Subsystem for Linux)**.
**Warning if you use Docker:** Docker changes the default WSL distro to a lightweight Alpine version that lacks `apt` and development tools. 

To configure WSL correctly:
1. Open PowerShell as Administrator.
2. Install Ubuntu: `wsl --install -d Ubuntu`
3. Set it as the default distro: `wsl --set-default Ubuntu`
4. Type `wsl` to enter the Ubuntu terminal. Run all the following steps inside it.

## 2. Dependencies (Linux)

Install the standard C++ compilation tools:
```bash
sudo apt update
sudo apt install build-essential
```

## 3. Global Compilation Shortcut (`mk`)

Instead of copying a `Makefile` into every single problem folder, we use a global shell function to compile our code.

Open your shell configuration file (usually `~/.bashrc`):
```bash
nano ~/.bashrc
```

Paste the following function at the end of the file:
```bash
mk() {
    g++ -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++17 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts -DDEBUG "$1.cpp" -o "$1"
}

start() {
    # Executa o Python. Mensagens de erro/logs vão para a tela, e o caminho final fica em TARGET_DIR
    TARGET_DIR=$(python3 setup/start.py "$@")
    
    # Se a resposta do Python for um diretório válido, entra nele
    if [ -d "$TARGET_DIR" ]; then
        cd "$TARGET_DIR"
        echo "[OK] Ambiente de competição pronto em: $TARGET_DIR"
    fi
}
```

Save, exit, and apply the changes:
```bash
source ~/.bashrc
```

## 4. Daily Workflow

To solve any problem, navigate to the desired folder inside `contests/` or `practice/`, and:
1. Copy the desired template from the `setup/` folder (e.g., `icpc.cpp` or `usaco.cpp`) and rename it (e.g., `A.cpp`).
2. Compile using our shortcut:
   ```bash
   mk A
   ```
3. Run the compiled binary:
   ```bash
   ./A
   ```