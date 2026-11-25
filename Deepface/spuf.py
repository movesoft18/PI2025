from deepface import DeepFace

result = DeepFace.analyze(
    img_path="image1.jpg",
    actions=["emotion"],
    anti_spoofing=True,
    enforce_detection=False,
)

for r in result:
    print("Живое лицо:", r["is_real"])
    print("Уверенность:", round(r["antispoof_score"], 3))
    print("Эмоция:", r["dominant_emotion"])