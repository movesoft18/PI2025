from ultralytics import YOLO
import cv2

model = YOLO("yolo26n-pose.pt")

# Имена точек
keypoint_names = [
    "nose", "left_eye", "right_eye", "left_ear", "right_ear",
    "left_shoulder", "right_shoulder", "left_elbow", "right_elbow",
    "left_wrist", "right_wrist", "left_hip", "right_hip",
    "left_knee", "right_knee", "left_ankle", "right_ankle",
]

cap = cv2.VideoCapture(0)
if cap.isOpened():
    while True:
        ret, frame = cap.read()
        if not ret: break
        results = model(frame)
        r = results[0]
        cv2.imshow("Image", cv2.resize(r.plot(),None, fx=2, fy=2))
        if cv2.waitKey(1) == 27: break
        # Для каждого человека
        for person_idx, person_kps in enumerate(r.keypoints.data):
            print(f"\nЧеловек {person_idx + 1}:")
            for kp_idx, kp in enumerate(person_kps):
                x = float(kp[0])
                y = float(kp[1])
                conf = float(kp[2])
                name = keypoint_names[kp_idx]
                print(f"  {name:15s}  ({x:.0f}, {y:.0f})  conf={conf:.2f}")
    cap.release()