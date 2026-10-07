import cv2

cap = cv2.VideoCapture("Обморок1.mp4")
if cap.isOpened():
    while True:
        ret, frame = cap.read()
        if not ret: break
        cv2.imshow("Video", frame)
        key = cv2.waitKey(30)
        if key == 27: break
    cap.release()