#import "@preview/touying:0.5.5": *
#import "@preview/clean-math-presentation:0.1.1": *

#show: clean-math-presentation-theme.with(
  config-info(
    title: [An example presentation to show how this template can be used],
    short-title: [Short title that will be shown in the footer],
    authors: (
      (name: "First Author", affiliation-id: 1),
      (name: "Second Author", affiliation-id: 2),
      (name: "Third Author", affiliation-id: 1)),
    author: "Presenting Author",
    affiliations: (
      (id: 1, name: "Fancy Department, University of Somewhere"),
      (id: 2, name: "Important Institute, Nice University"),
    ),
    date: datetime(year: 2024, month: 11, day: 20),
  ),
  config-common(
    slide-level: 2,
    //handout: true,
    //show-notes-on-second-screen: right,
  ),
  progress-bar: false,
)



// == Outline <touying:hidden>

// #components.adaptive-columns(outline(title: none))

= First Section

#slide(title: "1) Polymorphism")[
  Polymorphism is useful here
]

#slide(title: "2) Client update")[
  TODO
]

#slide(title: "Polynomials - 1")[
  We define a new abstract class `Function` representing a mathematical function. This class provides pure virtual methods for evaluating the function at a given point, computing its derivative, and displaying the informations about the function.

```cpp
class Function {
    protected:
        std::string name;
    public:
        Function(const std::string& i_name) : name(i_name) {}
        virtual
        double eval(double x0) = 0;
        virtual
        Function* derivative() = 0;
        virtual
        void display() = 0;
};
```
]

#slide(title: "Polynomials - 2")[

We implement the derivative class `Poly0`, `Poly1`, and `Poly2` representing polynomials of degree 0, 1, and 2 respectively. Each class implements the methods defined in the `Function` class. They have more specific attributes for each coefficient of the polynomial. For the derivative method each class returns a new instance of the appropriate polynomial class representing the derivative.

In the `main` function, we create three instances of these polynomial classes and demonstrate polymorphism by storing them in a vector of `Function*`. We then display the informations about each polynomial and evaluate the derivative of each polynomial at the point $x=1$.
]