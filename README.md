# Prediction Template Learning
Prediction Template Learning (PTL) is an online machine learning algorithm that makes predictions about the environment to improve itself.

[Theory (Self-Organizing Predictions)](https://github.com/CarsonScott/self-organizing-predictions)

[Learning Algorithm ](https://github.com/CarsonScott/TLearner)

## Prediction Template Learning
The prediction template learning (PTL) algorithm learns to make accurate predictions through a self-organizing, expectation-maximization system.

### Correction

At each timestep, the system receives an array as input, called a “state”. Each value in the state array is compared to a value in the predicted template- an array selected at the previous timestep as a prediction for the current state.

The difference between the values of the prediction and the values of the state are calculated and multiplied by a learning rate. The results are then added to the values of the template which was selected at the previous timestep. In other words, the template is adjusted to better match the state.

When a template is adjusted, the values become increasingly aligned with those of the observed state. This means that the template more accurately represents the current state than it previously had prior to the adjustment. In other words, the difference between the template and the state becomes smaller with each adjustment.

### Prediction

After the correction phase is complete, the system moves on to the prediction phase. It's important to note here that each template contains two individual arrays.

The current state is compared to the first array of every template. The template whose first array best matches the state is selected, and the second array becomes the prediction for the next timestep.

## Data
Now for some data collected while running tests. To test PTL's prediction ability, I generated random sequences of inputs and fed it to the algorithm, then calculated and plotted the error at each time step. 

In this test, each input vector is exactly 10 values long, and the sequence is 100 inputs in total.
![Fig. 1](https://github.com/CarsonScott/Prediction-Template-Learning/blob/master/img/figure_1.png)
Fig. 1

As you can see, the error rate decays exonentially and, given enough time to train, converges to zero. This next test also contains a 100-input sequence, however the inputs are now 50 values long instead of 10. 

![Fig. 2](https://github.com/CarsonScott/Prediction-Template-Learning/blob/master/img/figure_2.png)
Fig. 2

This time I've doubled the inputs in a sequence, raising the the total number of patterns the algorithm must learn to two-hundred.

![Fig. 3](https://github.com/CarsonScott/Prediction-Template-Learning/blob/master/img/figure_3.png)
Fig. 3

It takes roughly twice as long to learn double the amount of information from the previous tests. Time spent learning appears to scale linearly with the amount of material that needs to be retained, which reflects the way humans learn.

I raised the input size back up to 50 and kept the length of the sequence at 200.

![Fig. 4](https://github.com/CarsonScott/Prediction-Template-Learning/blob/master/img/figure_4.png)
Fig. 4
