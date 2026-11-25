from deepface import DeepFace

result = DeepFace.analyze(
    img_path="trump.png",
    actions=["age", "gender", "emotion"],
)

print(result)