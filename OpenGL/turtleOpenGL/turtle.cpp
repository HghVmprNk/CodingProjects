#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <vector>

// Structure to store vertex coordinates
struct Point {
    int x, y;
    Point(int x_, int y_) : x(x_), y(y_) {}
};

// Variables to store polygon type and vertices
char currentShape = ' '; // 't' for triangle, 'r' for rectangle
std::vector<Point> vertices; // Stores vertices of the polygon

// Function to draw the polygon based on the vertices
void drawPolygon() {
    if (currentShape == 't' && vertices.size() == 3) {
        glColor3f(0.0, 0.0, 0.0); // Black color for triangle
        glBegin(GL_TRIANGLES);
        for (const auto& vertex : vertices) {
            glVertex2i(vertex.x, vertex.y);
        }
        glEnd();
    } else if (currentShape == 'r' && vertices.size() == 2) {
        glColor3f(0.0, 0.0, 0.0); // Black color for rectangle
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 4; ++i) {
            int idx = i % 2;
            glVertex2i(vertices[idx].x, vertices[i / 2].y);
        }
        glEnd();
    }
}

// Function to handle mouse clicks
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        vertices.push_back(Point(x, glutGet(GLUT_WINDOW_HEIGHT) - y)); // Invert y-coordinate
        glutPostRedisplay();
    }
}

// Function to handle keyboard events
void keyboard(unsigned char key, int x, int y) {
    if (key == 't' || key == 'r') {
        currentShape = key;
        vertices.clear(); // Clear previous vertices
        glutPostRedisplay();
    }
}

// Function to display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw the polygon
    drawPolygon();

    glFlush();
}

// Function to initialize OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT)); // Set the viewing area
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Draw Shapes");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
