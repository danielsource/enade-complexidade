docname = complexidade

all: build/$(docname).pdf

build/$(docname).pdf: $(docname).tex build/$(docname).bbl
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory build $(docname).tex
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory build $(docname).tex

build/$(docname).bbl: ref.bib
	mkdir -p build
	pdflatex -interaction=nonstopmode -halt-on-error -output-directory build $(docname).tex
	biber build/$(docname)

clean:
	rm -fr build
