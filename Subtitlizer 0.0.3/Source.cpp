#include "MyForm.h"
#include <stdio.h>
#include <GLFW/glfw3.h>

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavcodec/codec_id.h>
#include <libswscale/swscale.h>
#include <inttypes.h>
}


using namespace Subtitlizer003;

int main()
{
	Application::Run(gcnew MyForm);
	bool load_frame(const char* filename, int* width_out, int* height_out, unsigned char** data_out); {

		printf("Beginning to encode\n");
		// declare format and codec contexts, also codec for decoding
		AVFormatContext* fmt_ctx = avformat_alloc_context();

		AVCodecContext* codec_ctx = avcodec_alloc_context3(NULL);
		AVCodecContext* av_codec;
		AVStream* in_stream = nullptr;
		AVStream* out_stream = nullptr;
		AVCodec* codec;
		const AVCodec* Codec = NULL;
		int ret = 0;
		char* filename = (char*)"D:\\Youtube Videos\\Needs Edtiting\\2023-03-01 16-56-21.mp4";
		int VideoStreamID = -1;
		AVCodecParameters* av_codec_params;
		AVFrame* frame = NULL;
		AVPacket* packet = NULL;

		// open input file
		if ((ret = avformat_open_input(&fmt_ctx, filename, NULL, NULL)) < 0)
		{
			av_log(NULL, AV_LOG_ERROR, "cannot open input file\n");
			goto end;
		}

		//get stream info
		if ((ret = avformat_find_stream_info(fmt_ctx, NULL)) < 0)
		{
			av_log(NULL, AV_LOG_ERROR, "cannot get stream info\n");
			return false;
		}

		// get video stream index
		for (int i = 0; i < fmt_ctx->nb_streams; i++)
		{

			if (fmt_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
			{
				auto stream = fmt_ctx->streams[i];
				av_codec_params = fmt_ctx->streams[i]->codecpar;
				VideoStreamID = i;
				break;
			}

			if (!fmt_ctx) {
				continue;
			}
			if (av_codec_params->codec_type == AVMEDIA_TYPE_VIDEO) {

			}
		}

		if (VideoStreamID < 0)
		{
			av_log(NULL, AV_LOG_ERROR, "No video stream\n");
			return false;
		}

		// dump video stream info
		av_dump_format(fmt_ctx, VideoStreamID, filename, false);

		//alloc memory for codec context
		//codec_ctx = avcodec_alloc_context3(NULL);


		Codec = avcodec_find_decoder(codec_ctx->codec_id);
		codec_ctx = avcodec_alloc_context3(Codec);
		if (!codec_ctx) {
			printf("Couldn't create AVCodecContext\n");
			return false;
		}


		// find decoding codec
		//codec_ctx = avcodec_alloc_context3(NULL);
		codec_ctx->codec_id = fmt_ctx->streams[VideoStreamID]->codecpar->codec_id;
		Codec = avcodec_find_decoder(codec_ctx->codec_id);



		if (Codec == NULL)
		{
			av_log(NULL, AV_LOG_ERROR, "No decoder found\n");
			goto end;
		}

		// try to open codec
		if (ret = avcodec_open2(codec_ctx, Codec, NULL) < 0)
		{
			av_log(NULL, AV_LOG_ERROR, "Cannot open video decoder\n");
			goto end;
		}




		printf("\nDecoding codec is : %s\n", Codec->name);





		// clear and out
	end:
		//codec_ctx = avcodec_alloc_context3(Codec);

		if (!codec_ctx) {
			printf("Couldn't create AVCodecContext\n");
			return false;
		}

		if (avcodec_parameters_to_context(codec_ctx, av_codec_params)) {


			printf("couldn't initizalize AVCodecContext \n", ret);

			return false;
		}
		if (avcodec_open2(codec_ctx, Codec, NULL) < 0) {
			printf("couldn't open codec\n");
		}




		AVFrame* av_frame = av_frame_alloc();
		if (!av_frame) {
			printf("Couldn't allocate AVFrame\n");
			return false;
		}

		AVPacket* av_packet = av_packet_alloc();
		if (!av_packet) {
			printf("Couldn't allocate AVPacket\n");
			return false;
		}

		int video_stream_index = -1;

		if (VideoStreamID < 0)
		{
			av_log(NULL, AV_LOG_ERROR, "No video stream\n");
			goto end;
		}
		else
		{
			video_stream_index = VideoStreamID;
		}



		if (!av_frame || !av_packet) {
			// error handling code
			printf("Couldn't allocate memory for frame\n");
		}

		int response;
		while (av_read_frame(fmt_ctx, av_packet) >= 0) {

			if (av_packet->stream_index != video_stream_index) {
				continue;
			}


			response = avcodec_send_packet(codec_ctx, av_packet);
			if (response < 0) {
				char errbuf[AV_ERROR_MAX_STRING_SIZE];
				av_strerror(response, errbuf, AV_ERROR_MAX_STRING_SIZE);
				printf("Failed to decode packet: %s\n", errbuf);
			}

			response = avcodec_receive_frame(codec_ctx, av_frame);
			if (response == AVERROR(EAGAIN) || response == AVERROR_EOF) {
				return false;
			}
			else if (response < 0) {
				char errbuf[AV_ERROR_MAX_STRING_SIZE];
				av_strerror(response, errbuf, AV_ERROR_MAX_STRING_SIZE);
				printf("Failed to decode frame: %s\n", errbuf);
				return false;
			}
			av_packet_unref(av_packet);
			break;
		}


		unsigned char* data = new unsigned char[av_frame->width * av_frame->height * 3];
		for (int x = 0; x < av_frame->width; ++x) {
			for (int y = 0; y < av_frame->height; ++y) {
				data[y * av_frame->width * 3 + x * 3] = 0xff;
				data[y * av_frame->width * 3 + x * 3 + 1] = 0x00;
				data[y * av_frame->width * 3 + x * 3 + 2] = 0xff;
			}
		}

		av_packet_free(&av_packet);
		avformat_close_input(&fmt_ctx);
		avformat_free_context(fmt_ctx);
		avcodec_free_context(&codec_ctx);
		av_frame_free(&frame);
		av_packet_free(&packet);

		printf("Ending decode\n");
		system("PAUSE");

		return 0;
	}
}