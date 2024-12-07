#ifndef FIND_ELEMENT_FUNCTION_H_
#define FIND_ELEMENT_FUNCTION_H_

template<typename T>
size_t findElementInArray(T array[], size_t size, T elem) {
	if (array == nullptr) {
		return size;
	}

	for (size_t i = 0; i < size; i++) {
		if (array[i] == elem) {
			return i;
		}
	}

	return size;
}

#endif // FIND_ELEMENT_FUNCTION_H_