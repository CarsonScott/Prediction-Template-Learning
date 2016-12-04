# Template Prediction Network
The Template Prediction Network, is an online learning algorithm that observes the current input state and selects a predicted state for the following time step. It compares the prediction to the actual state and adjusts accordingly, enabling more accurate predictions in the future.

States are stored in state-pairs as "templates". A state-pair represents a state transition from an initial state to the following state. The state templates are adjusted according to some measured error between the ideal (stored) and measured (actual) input. This expectation-maximization process drives the system toward the lowest possible error measurement between ideal and measured states.

## Network Structure
The structure is an abstraction of a multilayer perceptron in which the state-pairs correspond with hidden units and the predicted state values with output units. The input layer remains the same (i.e. propagates signals from the environment to the hidden layer).

At each time step the TPN has three main responsibilities. First, the input is compared to a selected state (prediction) from the previous time step. The prediction's state-pair (for which it is the final state) is updated to better resemble the measured input. 
Second, the input is compared to the initial states for each state-pair. The similarities are computed to select the best state-pair, and the final state is set as the prediction for the following time step. 
Finally, the selected state-pair's initial state is compared to the input and updated to better resemble to measured state.

TPN distinguishes itself from MLP's through its learning/adaptation method. The hidden layer is the only adaptable component and is responsible for the network's development as a whole. Hidden units are updated by comparing the predicted initial and final states to the actual states and correcting the error. The adjusted state-pair has a closer resemblence to the measured states, and thus provides more accurate predictions for the future.
