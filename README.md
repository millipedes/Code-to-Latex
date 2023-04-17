# :star: Purpose
I like to write code into latex documents sometimes, and one thing that really
annoys me is the translation of the code. So this stript takes in a file. So I
add these little newcommands in my preface:
```
\newcommand{\csfont}[1]{\fontfamily{cmtt}\selectfont #1}
\newcommand{\tab}{$\quad$}
```
Then I use this script over some code:
```
python to_tex.py -f path/to/file.code
```
And pow immediate good looking code on your clipboard.

# :hammer: Dependencies
This project dependes on:
 - argparse (should be in your default python)
 - pyclip
