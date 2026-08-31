all: build/questoes.pdf

build/questoes.pdf: questoes.tex
	mkdir -p build
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory build $<

clean:
	rm -r build
