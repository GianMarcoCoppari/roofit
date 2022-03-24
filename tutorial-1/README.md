# TUTORIAL 1

## EXERCISE 1 - FIT OF AN UNBINNED DATASET
Edit the macro `roofit_empty.cpp` and, following the comments inside, create a Crystal Ball PDF with 
* ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}\mu=0),
* ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}\sigma=1),
* ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}\alpha=1.5),
* ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}n=1.5).

Change ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}\sigma) to ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}0.3) and visualize the PDF. Generate an unbinned dataset of ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}10000) events. Make a Fit with Maximum Likelihood and visualize the results.
_Tips_:
* Use information from the slides shown during the lecture or from RooFit Manual at par 2
* Refer to the tutorial `rf101_basics.cxx`
* Find the definition of `RooCBshape` in the `ROOT Class reference`

Submit the macro as `ex_2020_1.cpp` and the image of the canvas in png format.

## EXERCISE 2 - FIT OF A BINNED DATASET

Edit the macro `roofit_empty.cpp` and, following the comments inside, create an Exponential PDF with rate ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}\lambda=-1/\tau) where ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}\tau=3) is the _mean lifetime_. Visualize the PDF. 
Generate a binned dataset of ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}1000) events (bin width equal to ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}0.5)). Make a Fit with Maximum Likelihood. Visualize the results.
Tips:
* Define the mean life as a `RooRealVar` and express the exponential rate using `RooFormulaVar`
* The binning of the returned `RooDataHist` is controlled by the default binning associated with the observables generated. To set the number of bins in `x` to `200`, do e.g. `x.setBins(200)` prior to the call to `generateBinned()`

Submit the macro as `ex_2020_1.cpp` and the image of the canvas in png format.

## EXERCISE 3 – Import a binned dataset, create a model using the factory, fit the model (LHC-b)
One of the main objectives of the LHC--b experiment is the study of the CP violation through the decay of different particles, like, for example, the ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}b)--flavored mesons.
Due to the short half-life, these particles can be observed by reconstructing their decay products and analyzing the so-called *invariant mass spectrum*.
The mass of the mesons is estimated by fitting a Breit-Wigner distribution.
In `B0sInvariantMass.root` an example of invariant mass spectrum for a ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}B_{s}^{0}) meson is stored.
Create a macro to open the `B0sInvariantMass.root` file and import the corresponding binned dataset. Using `RooFactory` and `RooWorkspace`, create a Breit-Wigner model. Fit the model to the binned dataset. Create a Gaussian function and fit to the data. Finally plot the data, and the BW and Gaussian distribution to the same canvas.
_Tips_:
* define the `RooRealVar` out of the factory, read and import the data from the file and import in the workspace using `RooWorkspace::import()`. 
* Compare the fitted value with the particle mass reported in the Particle Data Group. You can see how to import data here: https://root.cern.ch/doc/master/rf102__dataimport_8C.html

Submit the macro as `ex_12_2.cpp` and the image of the canvas in png format.

## EXERCISE 4 - The Central Limit Theorem: Sum of random variables
Using RooFit, define ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}N=8) independent random variables ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{1}), ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{2}), ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{3}), ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}\dots) uniformly distributed between ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}0) and ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}1). Then, define a new variable as the sum of the ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}N) random variables ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{\text{sum}}=\sum_{i=1}^{N}x_{i}).

Generate an unbinned dataset of ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}10000) events of variables ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{1}), ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{2}), ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{3}), ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}\dots).
You may be interested in the estimation of the expected mean and standard deviation of ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{\text{sum}}) (the sum of ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}N) measurements with a uniform distribution). It’s up to you to calculate it on the paper (it’s not expected you submit the solution).

Use the formulas ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}\sigma=\sqrt{V(x)}=\sqrt{\overline{x^{2}}-\overline{x}^{2}}), ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}\overline{x}=\int_{\Omega}xf(x)\,dx) and ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}\overline{x}^{2}=\int_{\Omega}x^{2}f(x)\,dx) where ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}f(x)) is the distribution you are averaging over (For this case where ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}f(x)) is a uniform distribution in range ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}[0,\,1]), namely ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}f(x)=1))

The _Central Limit Theorem_ predicts that the sum of ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}N) measurements has a Gaussian distribution in the limit of ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}N\to\infty) independent of the distribution of each individual measurement.
Then, create a Gaussian p.d.f. for ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{\text{sum}}) with mean and sigma as calculated before.
Make a Fit with Maximum Likelihood. Visualize the results.
Tips:
* the product of random variable is distributed according a p.d.f. which is the product of the single p.d.f.s (use `RooProdPdf`)
* the variable “sum of random variable” can be defined in `RooFit` by adding a formula to the generated dataset, as shown in this example for 2 variables: 
```c++
// Construct formula to calculate the sum events
RooFormulaVar fsum{"xsum", "var1+var2 ", RooArgList{var1, var2} ;
// Add column with variable xsum to previously generated dataset
auto xsum = (RooRealVar*)data->addColumn(fsum); 
```
- define a Gaussian model for ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{\text{sum}}) (sum of variables). With this respect, ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{\text{sum}}) behaves exactly as any other `RooRealVar`, even defined using `RooFormulaVar`.
- `Range` and `Bins` are property of a `RooRealVar`. Given that ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{\text{sum}}) is defined using a `RooFormulaVar` and not with the `RooRealVar` class constructor, you have to explicitly specify a range and a binning to obtain a frame from ![formula](https://render.githubusercontent.com/render/math?math=\color{gray}x_{\text{sum}})
```c++
auto plot = xsum->frame(Bins(40), Title("Sum of Random variables"), Range(0., 6.));
```
- Don’t’ forget to adjust the range.

Submit `ex16.cxx` and the image of the canvas in png format.