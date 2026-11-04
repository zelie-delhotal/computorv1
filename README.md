*this project has been created as part of the 42 post-common-core by gdelhota*

# Description:
The goal of the project is to write a program which, when given a polynomial equation, will write its reduced form, the polarity of the discriminant and the eventual solutions in $I$. This solver only works for equation up to the 2nd degree.
The language choice being free, I chose C++ because I want to reuse the implemented solution for GPU 3D rendering later.

# Instructions:
Run `make` at the root of the project to compile it. Then run it with `./computor <your equation>`
Example:
```
$>./computor "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
Reduced form: 4 * X^0 + 4 * X^1 - 9.3 * X^2 = 0
Polynomial degree: 2
Discriminant is strictly positive, the two solutions are:
0.905239
-0.475131
```

# Ressources:
[Markdown math notation](https://www.upyesp.org/posts/makrdown-vscode-math-notation/)
[Polynomial equations on Wikipedia](https://en.wikipedia.org/wiki/Algebraic_equation)

# AI Usage:

No AI has been used for this project.
