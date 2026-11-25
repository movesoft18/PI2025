from deepface import DeepFace
import cv2

cap = cv2.VideoCapture(0)
if cap.isOpened():
    while True:
        ret, frame = cap.read()
        if not ret: break
        try:
            # face_objs = DeepFace.extract_faces(
            #     img_path=frame,
            #     anti_spoofing = True
            #     )
            face_objs = DeepFace.analyze(
                img_path=frame,
                actions=["emotion"],
                anti_spoofing=True,
                enforce_detection=False,
)
            print(face_objs)
        except:
            pass
        cv2.imshow("Image", frame)
        if cv2.waitKey(300) == 27: break
    #assert all(face_obj["is_real"] is True for face_obj in face_objs)

# for r in result:
#     print("Живое лицо:", r["is_real"])
#     print("Уверенность:", round(r["antispoof_score"], 3))
#     print("Эмоция:", r["dominant_emotion"])