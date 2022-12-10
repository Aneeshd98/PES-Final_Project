# Final_Project
## Brightness control of LED based on temperature.

<p align="justify"> In this project, I used the temperature sensor which is present on the FRDM-KL25Z board to measure/read the temperature and based on the temperature readings change the brightness of the LED using PWM. </p>

<p align "justify"> Follwing features/functionalities of  KL25Z are used: </p>

<b>1. GPIO</b>

<b>2. PWM</b>

<b>3. TPM</b>

<b>4. ADC</b>

<b>5. Embedded Temperature Sensor</b>

### Basic Temperature Sensor Reading

<p align="justify"> The SO8ADC module has a P-N transistor junction with temperature dependent properties acting as an embedded temperature sensor. The voltage across this junction rises or lowers with temperature allowing silicon to act as a temperature sensor. Figure 1 shows the typical ADC readings of the temperature sensor output across a range of temperatures. </p>

| ![Typical%20ADC%20Temperature%20Readings.PNG](https://github.com/Aneeshd98/PES-Final_Project/blob/main/Typical%20ADC%20Temperature%20Readings.PNG) | 
|:--:| 
| *Figure 1.  Typical ADC Temperature Readings* |

<p align="justify"> The graph shows that the temperature sensor output is linear and dependant on VDD. The temperature sensor output voltage is highest at cold temperatures and lowest at hot temperatures. For VDD = 3 V, the readings range from 277d at –40°C down to 176d at 130°C. An approximate transfer function demonstrated in the following sections represents this behavior. </p>

<p align="justify"> The temperature sensor reading most accurately represents the temperature of the die and, due to proximity, the leads and the PCB board connected to it. For many applications, the desired temperature may differ from the die’s temperature. For example, the die temperature can differ from the temperature of a room’s air flow. </p>

###  Using Typical Parameters Provided by the Data Sheet

<p align="justify"> Use the typical parameters provided by the HCS08 data sheet to perform a temperature reading. An approximate transfer function describes the temperature sensor. </p>

| ![transfer_function.PNG](https://github.com/Aneeshd98/PES-Final_Project/blob/main/transfer_function.PNG)| 
|:--:| 
| *Figure 2.* |

### Temperature Reading Flowchart

| ![Temperature%20Reading%20Flowchart.PNG.jpg](https://github.com/Aneeshd98/PES-Final_Project/blob/main/Temperature%20Reading%20Flowchart.PNG.jpg)| 
|:--:| 
| *Figure 3.* |

### Video link
https://github.com/Aneeshd98/PES-Final_Project/blob/main/PES_Final_Project_v1.mp4
## Screenshot

<p align="justify"> Figure 4. Shows the temperature variations observed by the temperature sensor integrated in FRDM-KL25Z </p>

| ![temp_range_screenshot.png](https://github.com/Aneeshd98/PES-Final_Project/blob/main/temp_range_screenshot.png)| 
|:--:| 
| *Figure 4. Temperature  variations.* |


<p align="justify">  </p>
