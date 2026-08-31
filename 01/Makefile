all: build/questoes.pdf

build/questoes.pdf: questoes.tex ref.bib
	mkdir -p build
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory build $<
	biber build/questoes
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory build $<
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory build $<

clean:
	rm -fr build
