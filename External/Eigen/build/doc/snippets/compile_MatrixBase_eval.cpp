#include <Eigen/Core>
#include <Eigen/Array>
#include <Eigen/LU>
#include <Eigen/Cholesky>
#include <Eigen/Geometry>

using namespace Eigen;
using namespace std;

int main(int, char**)
{
  Matrix2f M = Matrix2f::Random();
Matrix2f m;
m = M;
cout << "Here is the matrix m:" << endl << m << endl;
cout << "Now we want to replace m by its own transpose." << endl;
cout << "If we do m = m.transpose(), then m becomes:" << endl;
m = m.transpose();
cout << m << endl << "which is wrong!" << endl;
cout << "Now let us instead do m = m.transpose().eval(). Then m becomes" << endl;
m = M;
m = m.transpose().eval();
cout << m << endl << "which is right." << endl;

  return 0;
}
