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

1. **Clone the repository**
```bash
git clone https://github.com/yourusername/egg-crack-detection.git
cd egg-crack-detection
