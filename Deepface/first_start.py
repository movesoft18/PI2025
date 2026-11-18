from deepface import DeepFace

image1 = 'image1.jpg'
image2 = 'image3.jpg'

try:
    result = DeepFace.verify(
        image1,
        image2,
        model_name="Facenet",
        detector_backend="retinaface",
        distance_metric="euclidean",
    )
except Exception as e:
    print(f'Ошибка - {e}')

print("Это один человек:", result["verified"])
print("Расстояние:", result["distance"])
print("Порог:", result["threshold"])


try:
    result = DeepFace.verify(
        image1,
        image2,
        model_name="ArcFace",
        detector_backend="retinaface",
        distance_metric="cosine",
    )
except Exception as e:
    print(f'Ошибка - {e}')

print("Это один человек:", result["verified"])
print("Расстояние:", result["distance"])
print("Порог:", result["threshold"])