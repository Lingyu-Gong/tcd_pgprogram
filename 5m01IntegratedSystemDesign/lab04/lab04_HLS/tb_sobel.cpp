  #include "sobel.h"
  #include "hls_opencv.h"
  int main(){
      cv::Mat img_src(cv::Size(MAX_WIDTH,MAX_HEIGHT),CV_8UC3);
      cv::Mat img_dst(cv::Size(MAX_WIDTH,MAX_HEIGHT),CV_8UC3);
      img_src = cv::imread("E:/pgprogram/tcd_pgprogram/5m01IntegratedSystemDesign/lab04_HLS/cat.jpg");
      AXI_STREAM stream_in, stream_out;
      cvMat2AXIvideo(img_src, stream_in);
      sobel_accel(stream_in, stream_out);
      AXIvideo2cvMat(stream_out, img_dst);
      cv::imwrite("E:/pgprogram/tcd_pgprogram/5m01IntegratedSystemDesign/lab04_HLS/cat_1.jpg", img_dst);

      return 0;
  }
