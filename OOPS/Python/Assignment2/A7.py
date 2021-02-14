import math
class Shape:
    def _str_(self):
        return "Base class, inheritance is needed for advanced use."

class SmoothShape(Shape):
    def _str_(self):
        return super()._str_()

class NonSmoothShape(Shape):
    def _str_(self):
        return super()._str_()

class TwoDimensionalShape(Shape):
    def _str_(self):
        return super()._str_()

class ThreeDimensionalShape(Shape):
    def _str_(self):
        return super()._str_()

class RegularPolygon(TwoDimensionalShape, NonSmoothShape):
    def _init_(self, length, sides = 3):
        self.sides = sides
        self.length = length

    def _getArea(self):
        perimeter = self.sides * self.length
        apothem = round(self.length / (2 * math.tan(math.pi/self.sides)), 3)
        area = (perimeter * apothem) / 2
        return area 
    
    def getArea(self):
        print("Area of regular polygon: {:.3f}".format(self._getArea()))

class Square(RegularPolygon):
    def _init_(self, length):
        super()._init_(length, 4)

    def getArea(self):
        print("Area of square: {:.3f}".format(super()._getArea()))

class Rectangle(TwoDimensionalShape, NonSmoothShape):
    def _init_(self, length, breadth):
        self.length = length
        self.breadth = breadth

    def getArea(self):
        print("Area of rectangle: {:.3f}".format(self.length * self.breadth))

class Circle(TwoDimensionalShape, SmoothShape):
    def _init_(self, radius):
        self.radius = radius

    def getArea(self):
        print("Area of circle: {:.3f}".format(math.pi * (self.radius ** 2)))

class Cuboid(ThreeDimensionalShape, NonSmoothShape):
    def _init_(self, length, breadth, height):
        self.length = length
        self.breadth = breadth
        self.height = height

    def getArea(self):
        area = 2 * (self.length * self.breadth + self.length * self.height + self.height * self.breadth)
        print("Area of cuboid: {:.3f}".format(area))

class Cube(ThreeDimensionalShape, NonSmoothShape):
    def _init_(self, length):
        self.length = length

    def getArea(self):
        area = 6 * (self.length ** 2)
        print("Area of cube: {:.3f}".format(area))

class Cone(ThreeDimensionalShape, NonSmoothShape):
    def _init_(self, height, base_radius):
        self.height = height
        self.base_radius = base_radius

    def getArea(self):
        area = (math.pi * self.base_radius * 2) + math.pi * self.base_radius * math.sqrt((self.base_radius * 2) + (self.height ** 2))
        print("Area of cone: {:.3f}".format(area))