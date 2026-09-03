all: build/complexidade.pdf

build/complexidade.pdf: complexidade.tex ref.bib
	mkdir -p build
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory build $<
	biber build/complexidade
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory build $<
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory build $<

clean:
	rm -fr build
