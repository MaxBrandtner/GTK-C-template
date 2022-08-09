#include <gtk/gtk.h>


#define APPLICATION_ID "com.example.Template"

#define UI_DIR_WINDOW LOCAL_DIR "Window.ui"



static void app_startup(GApplication *application){

}


static void app_activate(GApplication *application){
	GtkApplication *app = GTK_APPLICATION(application);

	GtkBuilder *build = gtk_builder_new_from_file(UI_DIR_WINDOW);

	GtkWidget  *window  = GTK_WIDGET(gtk_builder_get_object(build, "window"));

	g_object_unref(build);

	gtk_window_set_application(GTK_WINDOW(window), app);




	gtk_widget_show(window);
}




int main(int argc, char **argv){
	
	GtkApplication *app = gtk_application_new(APPLICATION_ID, G_APPLICATION_FLAGS_NONE);

	g_signal_connect(app, "startup", G_CALLBACK(app_startup), NULL);
	g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);


	int status = g_application_run(G_APPLICATION(app),argc, argv);


	g_object_unref(app);

	return status;
}
