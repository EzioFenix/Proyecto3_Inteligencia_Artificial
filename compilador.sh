# Compilador diapostivas
#pandoc -V lang=es --to=beamer --pdf-engine=xelatex  --standalone formato.yaml --output=Diapositivas/diapositivas.tex README.md
#pandoc -V lang=es --to=beamer --pdf-engine=xelatex formato.yaml --output=Diapositivas/diapositivas.pdf README.md
# compilar documentacion
pandoc -V lang=es --pdf-engine=lualatex --output=Documentacion/documentacion.pdf README.md
#pandoc -V lang=es --standalone --pdf-engine=lualatex --output=Documentacion/documentacion.tex README.md

# mv out.* ../Entregable/