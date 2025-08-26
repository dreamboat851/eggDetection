import cv2
import numpy as np
import serial
import time

MARGIN = 10  # pixels
ROW_SIZE = 30  # pixels
FONT_SIZE = 1
FONT_THICKNESS = 1
TEXT_COLOR = (0, 0, 0)  # black

# Open the serial port
ser = serial.Serial('COM3', baudrate=9600, timeout=1)

def visualize(image, detection_result) -> np.ndarray:
    """Draws bounding boxes on the input image and sends serial data based on detection result.
    Args:
        image: The input RGB image.
        detection_result: The list of all "Detection" entities to be visualized.
    Returns:
        Image with bounding boxes.
    """
    for detection in detection_result.detections:
        # Draw bounding_box
        bbox = detection.bounding_box
        start_point = bbox.origin_x, bbox.origin_y
        end_point = bbox.origin_x + bbox.width, bbox.origin_y + bbox.height
        # Use the orange color for high visibility.
        cv2.rectangle(image, start_point, end_point, (0, 165, 255), 3)

        # Draw label and score
        category = detection.categories[0]
        category_name = category.category_name
        probability = round(category.score, 2)
        result_text = category_name + ' (' + str(probability) + ')'
        text_location = (MARGIN + bbox.origin_x,
                         MARGIN + ROW_SIZE + bbox.origin_y)
        

        # Send serial data based on detection result and probability
        if probability >= 0.8:
            cv2.putText(image, result_text, text_location, cv2.FONT_HERSHEY_DUPLEX,
                    FONT_SIZE, TEXT_COLOR, FONT_THICKNESS, cv2.LINE_AA)
            if category_name == 'cracked':
                ser.write(b'cracked\n')  # Send 'cracked' to Arduino
            elif category_name == 'normal':
                ser.write(b'normal\n')  # Send 'normal' to Arduino

    time.sleep(0.1)
    return image
