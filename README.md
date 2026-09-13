(pt-BR)
Resumo de Complexidade de Algoritmos para Enade de Ciência da Computação
========================================================================


Pacotes recomendados
--------------------

Arch Linux:

    pacman -S --needed biber texlive-bibtexextra texlive-binextra texlive-fontsrecommended texlive-langportuguese texlive-latex texlive-latexextra texlive-mathscience texlive-plaingeneric texlive-publishers

Debian:

    apt install biber latexmk texlive-bibtex-extra texlive-fonts-recommended texlive-lang-portuguese texlive-latex-base texlive-latex-recommended texlive-latex-extra texlive-science texlive-plain-generic texlive-publishers


Compilação para PDF
-------------------

    latexmk -auxdir=build -pdf complexidade.tex
