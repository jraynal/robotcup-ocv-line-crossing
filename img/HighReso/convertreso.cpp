#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char* argv[])
{

  if (argc < 3)
    {
      cout<<"not enough argument"<<endl;
      return 0;
    }
  
  string input_name = argv[1];
  string output_name = argv[2];

  cv::Mat input;
  cv::Mat output(input.rows/2,input.cols/2, CV_8UC3, cv::Scalar(255,0,255));

  input = cv::imread(input_name, CV_LOAD_IMAGE_COLOR);

  if(! input.data ) // Check for invalid input
    {
      cout << "Could not open or find the image" << std::endl ;
      return -1;
    }


  cv::imshow( output_name, output );
  cv::imshow( input_name, input );

  cv::imwrite(output_name + ".jpg", output);
  cout<<input.size()<<endl;

  cv::waitKey(0);

  return 0;
}
