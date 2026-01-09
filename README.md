# Lego Colour Sorter
Fully automated LEGO colour-sorting system designed and prototyped for the Toronto LEGO Users Group (ToroLUG). Developed for Praxis II @ University of Toronto (Jan 2025 - April 2025).

##External Links

[Process Photos](https://www.canva.com/design/DAGj6-HOVCs/F2F9mz-JD6iF1pp3E96jQQ/edit?utm_content=DAGj6-HOVCs&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)

[Design Work](https://drive.google.com/drive/folders/1qVWLQaJ4YQJG44gx1dYV_5yEBJK0j_s4?usp=sharing)

[Proxy Testing](https://docs.google.com/document/d/1sEvf39hcPc-sCbPSVRZB1obtI7LL8aF-mVKAvm1DiM8/edit?usp=sharing)

[Requirements](https://docs.google.com/document/d/16xtPRu5nWoSMRV-YhNaZstuKKnbDuTDWdE4PJkdAXaE/edit?usp=sharing)

[Calculations](https://drive.google.com/file/d/1DZqr5AY5gptGB_TLBmOlQDHv4m626uK-/view?usp=sharing)

---

## Project Overview

This project focuses on the design and implementation of a **Colour LEGO sorting system** where LEGO pieces are transported, sensed, classified, and routed to the appropriate collection bin (red, green, blue, other).

Key goals:
- Reliable colour detection
- Iterative design based on user feedback
- Fully autonomous operation after startup

---

## System Components
1. Stepper-Drive Carousel --> unsorted LEGO compartment that feeds LEGO to the main sorting area
3. Ramp --> Alignment Guide to conveyor belt
4. Colour Sensor --> **TCS34725**
5. Conveyor Belt --> Driven by two servos, initiated by a button
6. Collection Plate --> Four compartments: red, green, blue, other

---

## Software & Hardware Stack

- **Microcontroller:** Arduino  
- **Sensor:** TCS34725 RGB Colour Sensor  
- **Actuators:** Servos, stepper motor  
- **Languages:** Arduino

---

## Code Structure

Each `.ino` file corresponds to a specific subsystem or development stage:

- `ColourSensorCalibration.ino`  
  Used to calibrate the TCS34725 colour sensor using outputted RGB values used for thresholding and classification.

- `ColourSorterFinal.ino`  
  Final integrated control program coordinating sensing, conveyors, and sorting logic.

- `StepperMotorCode-Carousel.ino`  
  Controls the stepper motor responsible for continuous rotation, initiated by the button.

- `TwoConveyorBeltServoCodeWithButton.ino`  
  Controls the servo-driven conveyor belts, including manual start/stop functionality via a button.

---

## Results & Impact

- Successfully demonstrated a working automated LEGO colour sorter prototype 
- Improved sorting reliability and efficiency
---

## Future Improvements

- Increase system scale and throughput for higher-volume LEGO sorting  
- Redesign container geometry and ramp cage to reduce jamming  
- Improve sorting speed using multiple colour sensors across the conveyor  
- Enclose the system with a transparent safety housing  
- Expand sorting beyond colour to size and shape using weight sensing and AI-based detection  
- Support dynamic colour combinations and increase the number of sortable colours  
- Add a GUI for user-defined sorting configurations and Arduino integration
  
---

## Acknowledgements

- Toronto LEGO Users Group (ToroLUG)  
- Praxis II instructors and mentors
- Collaborators Arya Ranadive, Heidi Ma and Arthur Chen 
- University of Toronto Engineering Science program  

---

## Author
**Affie Fan**  

