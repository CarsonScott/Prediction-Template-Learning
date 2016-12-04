# Prediction Network
The prediction network is an online learning algorithm that observes the current input state and selects a predicted state for the following time step. It compares the prediction to the actual state and adjusts accordingly, enabling more accurate predictions in the future.

States are stored in state-pairs as "templates". A state-pair represents a state transition from an initial state to the following state. The state templates are adjusted according to some measured error between the ideal (stored) and measured (actual) input. This expectation-maximization process drives the system toward the lowest possible error measurement between ideal and measured states.

## Network Structure
The structure is an abstraction of a multilayer perceptron in which the state-pairs correspond with hidden units and the predicted state is the output layer. The input layer remains the same (i.e. propagates signals from the environment to the hidden layer). 

PN's diverge from MLP's during the learning process. The hidden units are updated by comparing the predicted initial and final states to the actual states and correcting the error. The adjusted state-pair has a closer resemblence to the measured states, and thus provides more accurate predictions for the future.

The hidden layer is the only adaptive component and is responsible for the network's development as a whole. 
