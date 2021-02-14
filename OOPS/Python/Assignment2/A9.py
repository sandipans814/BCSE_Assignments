class Person:
    def _init_(self):
        self._name = ''
        self._age = -1
    
    @property
    def name(self):
        return self._name

    @property
    def age(self):
        return self._age

    @name.setter
    def name(self, value):
        self._name = value

    @name.deleter
    def delete(self):
        print("Deleting name property")
        del self._name

    @age.setter
    def name(self, value):
        self._age = value

    @age.deleter
    def delete(self):
        print("Deleting age property")
        del self._age