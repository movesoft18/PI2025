from deepface import DeepFace

result = DeepFace.find(
    img_path="image1.jpg",
    db_path="base/",
    model_name="Facenet",
    detector_backend="retinaface",
)

if len(result[0]) == 0:
    print("Ничего не найдено")
else:
    print(result)