import cv2
from deepface import DeepFace

cap = cv2.VideoCapture(0)
frame_count = 0
last_emotion = "?"

while cap.isOpened():
    ret, frame = cap.read()
    if not ret or cv2.waitKey(1) == 27:
        break

    if frame_count % 10 == 0:
        try:
            results = DeepFace.analyze(
                img_path=frame,
                actions=["emotion"],
                enforce_detection=False,
                silent=True,
            )
            if len(results) > 0:
                last_emotion = results[0]["dominant_emotion"]
        except Exception:
            pass

    cv2.putText(frame, last_emotion, (20, 50),
                cv2.FONT_HERSHEY_SIMPLEX, 1.5, (0, 255, 0), 3)
    cv2.imshow("Emotion", frame)

    frame_count += 1
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

cap.release()
cv2.destroyAllWindows()