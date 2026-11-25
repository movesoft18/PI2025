import cv2
from deepface import DeepFace
from collections import Counter, deque

cap = cv2.VideoCapture(0)
history = deque(maxlen=5)
frame_count = 0
display_name = "?"

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    if frame_count % 10 == 0:
        try:
            result = DeepFace.find(
                img_path=frame,
                db_path="face_base\\",
                model_name="Facenet",
                #detector_backend="retinaface",
                enforce_detection=False,
                silent=True,
            )

            if len(result[0]) > 0 and result[0].iloc[0]["distance"] < 0.40:
                name = result[0].iloc[0]["identity"].split("\\")[-2]
            else:
                name = "неизвестный"

            history.append(name)
            display_name = Counter(history).most_common(1)[0][0]
        except Exception:
            pass

    cv2.putText(frame, display_name, (20, 50),
                cv2.FONT_HERSHEY_SIMPLEX, 1.5, (0, 255, 0), 3)
    cv2.imshow("Who is there?", frame)

    frame_count += 1
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

cap.release()
cv2.destroyAllWindows()