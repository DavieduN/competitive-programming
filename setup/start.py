import os
import sys
import shutil
from datetime import datetime

def main():
    if len(sys.argv) < 3 or len(sys.argv) > 4:
        sys.stderr.write("Uso: start [live/virtual/mashup] [prefixo_da_pasta] [num_questoes (opcional)]\n")
        sys.exit(1)

    contest_type = sys.argv[1].lower()
    prefix = sys.argv[2]
    
    num_problems = 0
    if len(sys.argv) == 4:
        try:
            num_problems = int(sys.argv[3])
        except ValueError:
            sys.stderr.write("Erro: O número de questões deve ser um valor inteiro.\n")
            sys.exit(1)

    if contest_type == "mashup":
        contest_type = "mashups"
    elif contest_type not in ["live", "virtual", "mashups"]:
        sys.stderr.write("Erro: O tipo deve ser 'live', 'virtual' ou 'mashup'.\n")
        sys.exit(1)

    folder_name = prefix
    if contest_type == "mashups":
        agora = datetime.now().strftime("%Y-%m-%d_%H-%M")
        folder_name = f"{prefix}_{agora}"

    repo_root = os.getcwd()
    while not os.path.exists(os.path.join(repo_root, "setup")) and repo_root != "/":
        repo_root = os.path.dirname(repo_root)

    if repo_root == "/":
        sys.stderr.write("Erro: Execute este comando de dentro do seu repositório.\n")
        sys.exit(1)

    full_target_path = os.path.join(repo_root, "contests", contest_type, folder_name)
    template_path = os.path.join(repo_root, "setup", "template.cpp")

    os.makedirs(full_target_path, exist_ok=True)

    if num_problems > 0:
        letras = "abcdefghijklmnopqrstuvwxyz"
        for i in range(min(num_problems, 26)):
            letra = letras[i]
            file_path = os.path.join(full_target_path, f"{letra}.cpp")
            if not os.path.exists(file_path):
                shutil.copyfile(template_path, file_path)
        sys.stderr.write(f"[OK] {num_problems} arquivos base criados.\n")

    # Imprime apenas o caminho da pasta na saída padrão para o Bash capturar
    print(full_target_path)

if __name__ == "__main__":
    main()