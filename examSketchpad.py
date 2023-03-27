#line problem
def pointVsLine(p0, p1, p2):

    #setup
    x0 = p0[0]
    x1 = p1[0]
    x2 = p2[0]
    y0 = p0[1]
    y1 = p1[1]
    y2 = p2[1]

    #is formula for A and B were incorrect on original problem?
    #should be lineA = y0-y1, lineB = x1-x0
    #answers keep coming out inverse as given.
    #source: Fundamentals of Computer Graphics
    #By Steve Marschner, Peter Shirley
    #Page 
    lineA = y1-y0
    lineB = x0-x1 
    lineC = (x0*y1)-(x1*y0)

    #calculation
    return ((lineA*x2)+(lineB*y2)-lineC)

    print(lineA)
    print(lineB)
    print(lineC)

testPoint1 = (1,0)
testPoint2 = (10,5)
testPoint3 = (1,2)

print(pointVsLine(testPoint1, testPoint2, testPoint3))
