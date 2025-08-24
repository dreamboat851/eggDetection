# Automated Egg Crack Detection System

An automated system for detecting and sorting cracked eggs using deep learning and computer vision techniques.

## Overview

This project implements a preliminary automated system that uses deep learning to identify cracked eggs and mechanically sort them from normal eggs. The system combines computer vision, MediaPipe object detection, and Arduino-controlled hardware to create a complete automated quality control solution for egg processing.

## Features

- **Real-time Detection**: Uses MediaPipe framework for real-time egg crack detection
- **Deep Learning**: Employs transfer learning with MobileNet architecture
- **Automated Sorting**: Arduino-controlled servo motor system for physical egg sorting
- **Multiple Crack Types**: Detects gross cracks, hairline cracks, star cracks, and pinholes
- **Visual Feedback**: Real-time display with bounding boxes and confidence scores
- **Hardware Integration**: Seamless communication between PC and Arduino via serial interface

## System Architecture

The system consists of:
- **Computer Vision Module**: Real-time video processing and crack detection
- **Deep Learning Model**: TensorFlow Lite model based on MobileNet Multi AVG
- **Hardware Controller**: Arduino Uno for sensor and actuator coordination
- **Mechanical System**: Conveyor belt with servo motor sorting mechanism
- **Sensors**: Photoelectric proximity sensor for egg detection timing

## Hardware Requirements

- PC or Raspberry Pi (for processing)
- USB Camera/Webcam
- Arduino Uno
- Servo Motor
- Photoelectric Proximity Sensor
- Conveyor Belt System
- Connecting wires and breadboard
- Power supplies

## Software Requirements

- Python 3.8+
- OpenCV (`cv2`)
- MediaPipe
- NumPy
- PySerial
- TensorFlow Lite

## Installation

### 1. Clone the repository
```bash
git clone https://github.com/yourusername/egg-crack-detection.git
cd egg-crack-detection
```

### 2. Install Python dependencies
```bash
pip install opencv-python
pip install mediapipe
pip install numpy
pip install pyserial
```

### 3. Hardware Setup
- Connect Arduino Uno to your computer via USB
- Wire the servo motor to Arduino (typically pin 7)
- Connect photoelectric sensor to Arduino (typically pin 9)
- Set up conveyor belt system
- Position USB camera to capture eggs on conveyor belt

### 4. Arduino Setup
- Upload the Arduino sketch to your Arduino Uno board
- Ensure proper pin connections match your hardware setup

## Usage

### 1. Prepare the Model
- Ensure you have a trained TensorFlow Lite model (`.tflite` file)
- Place the model file in the project directory

### 2. Run the Detection System
```bash
python eggDetect_mod.py --model your_model.tflite --cameraId 0
```

### 3. System Parameters
- `--model`: Path to your TensorFlow Lite model
- `--maxResults`: Maximum number of detection results (default: 5)
- `--scoreThreshold`: Detection confidence threshold (default: 0.25)
- `--cameraId`: Camera ID (default: 0)
- `--frameWidth`: Camera frame width (default: 640)
- `--frameHeight`: Camera frame height (default: 480)

## File Structure

```
├── eggDetect_mod.py      # Main detection and processing script
├── utils.py              # Utility functions for visualization and communication
├── arduino_code.ino      # Arduino sketch for hardware control
├── README.md             # This file
└── models/               # Directory for trained models
```

## How It Works

1. **Image Capture**: USB camera continuously captures video frames of eggs on conveyor belt
2. **Detection**: MediaPipe processes frames to detect and classify eggs as 'cracked' or 'normal'
3. **Communication**: Results are sent to Arduino via serial communication (COM3, 9600 baud)
4. **Sorting**: When proximity sensor detects an egg, Arduino triggers servo motor based on classification
5. **Visual Feedback**: System displays real-time results with bounding boxes and confidence scores

## Training Data

The system was trained on a dataset of 148 images:
- 108 images for training
- 40 images for validation
- Categories: gross cracks, hairline cracks, star cracks, pinholes, and normal eggs
- Images collected from poultry farms and online sources

## Performance

- **Processing Speed**: Real-time processing with MediaPipe framework
- **Detection Threshold**: 80% confidence for positive classifications
- **Communication**: Serial communication at 9600 baud rate
- **Sorting Accuracy**: Successful mechanical sorting coordination with proximity sensor

## Configuration

### Serial Communication
- **Port**: COM3 (adjust in `utils.py` if different)
- **Baud Rate**: 9600
- **Timeout**: 1 second

### Detection Parameters
- **Confidence Threshold**: 0.8 (80%) for triggering sorting action
- **Visualization**: Orange bounding boxes (0, 165, 255)
- **Processing Delay**: 0.1 seconds between cycles

## Troubleshooting

**Camera Issues**:
- Verify camera ID (try different values: 0, 1, 2, etc.)
- Check camera permissions and connections

**Serial Communication Issues**:
- Verify COM port in Device Manager (Windows)
- Ensure Arduino is properly connected
- Check baud rate settings match (9600)

**Detection Issues**:
- Ensure proper lighting conditions
- Verify model file path and format
- Check camera positioning and focus

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## License

This project is developed for research purposes. Please cite appropriately if used in academic work.

## Citation

If you use this code in your research, please cite:

```
Bandara, N. M. S. M., & Pemasinghe, S. (2024). Development of a Preliminary Automated 
System for Sorting Cracked Eggs Based on Deep Learning. [Conference/Journal Name].
```

## Authors

- **Nawarathna Mudiyanselage Sathsarani Madushani Bandara** - Wayamba University of Sri Lanka
- **Dr. Sajeewa Pemasinghe** - Nāgānanda International Institute for Buddhist Studies (NIIBS)

## Acknowledgments

- Wayamba University of Sri Lanka
- Poultry farms in Moragollagama-Kurunegala area for providing access to egg samples
- MediaPipe and TensorFlow communities for excellent frameworks

---

For questions or issues, please open a GitHub issue or contact the authors.
