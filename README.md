# EEL7515 - Redes de Sensores sem Fio para IoT

Repositório das aulas práticas.

## 1. Ambiente de Desenvolvimento

Será necessário o Code Composer Studio ([CCS](http://www.ti.com/tool/CCSTUDIO)) e o [git](https://git-scm.com/).

Existem dois métodos para configurar o ambiente: 1.1) Pendrive Live; 1.2) Instalação do CCS no Linux.

#### 1.1 Pendrive Live

Acesse o [link](https://drive.google.com/open?id=1swg47RM-ScyB8wibqxiXi5v506OUtgYt) e baixe a imagem disponível. Descompacte e grave-a num pendrive de pelo menos 16GB¹. Para fazer isso utilize o [Rufus](https://rufus.ie/) para Windows e [Etcher](https://www.balena.io/etcher/) para linux (funciona no windows também).

Depois é só bootar pelo pendrive² e ao logar o ambiente de desenvolvimento estaŕá pronto para uso.

Porém, não deixe de fazer o update/updgrade do Mint. Faça isso antes da aula:

Atualize os repositórios do Linux Mint com o comando: sudo apt-get update 

Atualize o Linux Mint com o comando: sudo apt-get upgrade 

¹ mfrata: estou tentando encontrar uma forma de reduzir o tamanho da imagem. O tamanho ocupado dela é de apenas 5.6GB, entretanto ela ocupa 16GB descompacatada por causa do tamanho do dispositivo que ela foi gravada originalmente.

² Utilizar USB 3.0. Se não tiver, o sistema poderá ficar lento.

#### 1.2 Instalação do CCS no Linux

Baixe o CCS  para o [linux](http://processors.wiki.ti.com/index.php/Download_CCS#Code_Composer_Studio_Version_8_Downloads). Siga as [instruções](http://software-dl.ti.com/ccs/esd/documents/ccsv8_linux_host_support.html#installation-instructions)¹ de acordo com a distribuição² instalada. 

Atente à familia que será usada na disciplina:
![](https://i.imgur.com/HKt21Du.jpg)

¹ Assume-se que há um entendimento básico de comandos no terminal. Qualquer dúvida, entrar em contato com o monitor.

² mfrata: Instalei no Ubuntu 18.10:
Comando antes de executar o instalador, caso o instalador acuse erro de bibliotecas faltantes:

`sudo apt-get install libgtk2.0-0 libncurses5`

A interface gráfica travou no fim da instalação, porém a mesma foi concluída com sucesso. 

Encontrei os seguintes erros:
* `arm-none-eabi-gcc: Command not found`

* `Typemake: srec_cat: Command not found`

Para consertar, é só rodar o seguinte:
`sudo apt-get install gcc-arm-none-eabi srecord`

### 2 Git

`sudo apt install git`

### 3 Clonando o Repositorio

Crie uma conta no github. Faça um [fork](https://help.github.com/en/articles/fork-a-repo) deste repositorio. Substitua `<seu_usuario>` nos links abaixo

`git clone https://github.com/<seu_usuario>/rssf-iot --recursive`
 
 ou
 
 `git clone https://github.com/<seu_usuario>/rssf-iot`
 
 `git submodule init`
 
 `git submodule update`
